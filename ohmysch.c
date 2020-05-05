#include <stdio.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/types.h>
#include <sqlite3.h>
#include "libft.h"

void	print_status(int rc)
{
    if(!rc)
	{
		printf("███╗     ██╗███████╗███████╗    ██╗███████╗    ██╗  ██╗██████╗ \n");
		printf("███║     ██║██╔════╝██╔════╝    ██║██╔════╝    ██║  ██║╚════██╗\n");
		printf("███║     ██║█████╗  █████╗      ██║███████╗    ███████║ █████╔╝\n");
		printf("███║     ██║██╔══╝  ██╔══╝      ██║╚════██║    ╚════██║██╔═══╝ \n");
		printf("████████╗██║██║     ███████╗    ██║███████║         ██║███████╗\n");
		printf(" ╚══════╝╚═╝╚═╝     ╚══════╝    ╚═╝╚══════╝         ╚═╝╚══════╝\n");                                                         
	}
	else
	{
		ft_putstr_fd("NEED initializing by enter 'cmdo' command OR CHECK sqlite3_open PATH\n", 1); 
	}
}

int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    
    NotUsed = 0;
    
    for (int i = 0; i < argc; i++) 
	{
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    
    printf("\n");
    
    return (0);
}

void 	print_retrive_err(char **err_msg)
{
	fprintf(stderr, "Failed to select data\n");
    fprintf(stderr, "SQL error: %s\n", *err_msg);

    sqlite3_free(*err_msg);
}

int	main(void)
{ 
	char *db_path;
	int rc;
	rc = 0;
    sqlite3 *db;
	char *err_msg = 0;

/*
**	get userid and userinfo
**	http://forum.falinux.com/zbxe/index.php?document_srl=408418&mid=C_LIB
**/

	uid_t			user_id;
   	struct passwd	*user_pw;

	user_id  = getuid();            
	user_pw  = getpwuid(user_id);  

/*
**	get path for cmdo.db
*/

	db_path = ft_strjoin(user_pw->pw_dir, "/.local/bin/cmdo.db");
	print_status((rc = sqlite3_open(db_path, &db)));

/*
**	http://zetcode.com/db/sqlitec/
*/
	
	if (!rc)
	{
		char *sql = "SELECT * FROM todo_list";
		rc = sqlite3_exec(db, sql, callback, 0, &err_msg);
		if (!rc)
		{
			sqlite3_close(db);
			free(db_path);
			return (0);
		}
		else 
			print_retrive_err(&err_msg);
	}
    sqlite3_close(db);
	free(db_path);
    return (1);
}

