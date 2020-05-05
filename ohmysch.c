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

int		main(void)
{ 
	char *db_path;
	int rc;
	rc = 0;
    sqlite3 *db;

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
    rc = sqlite3_open(db_path, &db);
 
	print_status(rc);
 
    sqlite3_close(db);
	free(db_path);
    return (0);
}

