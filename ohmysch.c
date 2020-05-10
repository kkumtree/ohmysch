#define _XOPEN_SOURCE 
#include <stdio.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/types.h>
#include <sqlite3.h>
#include <time.h>
#include "libft.h"

void	print_status(int rc)
{
    if(!rc)
	{
		printf("██╗    ██╗██████╗██████╗    ██╗██████╗    ██╗  ██╗██████╗ \n");
		printf("██║    ██║██╔═══╝██╔═══╝    ██║██╔═══╝    ██║  ██║╚════██╗\n");
		printf("██║    ██║█████╗ █████╗     ██║██████╗    ███████║ █████╔╝\n");
		printf("██║    ██║██╔══╝ ██╔══╝     ██║╚═══██║    ╚════██║██╔═══╝ \n");
		printf("██████╗██║██║    ██████╗    ██║██████║         ██║███████╗\n");
		printf(" ╚════╝╚═╝╚═╝    ╚═════╝    ╚═╝╚═════╝         ╚═╝╚══════╝\n");                                                         
	}
	else
	{
		ft_putstr_fd("NEED initializing by enter 'cmdo' command OR CHECK sqlite3_open PATH\n", 1); 
	}
}

/*
** https://www.it-note.kr/145 day_parsing
** https://kldp.org/node/111679
*/

int	getday(char *date)
{
	struct tm	tm1;
	struct tm	tm2;
	time_t		t1;
	time_t		t2;
	char 		*e;

	ft_memset(&tm1, 0, sizeof(tm1));
	ft_memset(&tm2, 0, sizeof(tm2));

	e = strptime(date, "%Y-%m-%d", &tm1);
	if (e && *e)
	{
		printf("(fix Due date)\n");
	}
//	e = strptime(date, "%Y-%m-%d", &tm2);
//	if (e && *e)
//		ft_putstr_fd("err_tm2\n", 2);
	t1 = mktime(&tm1);
//	t2 = mktime(&tm2);
	t2 = time(NULL);
	return (((difftime(t1, t2))/(60 * 60 * 24)));
}

void		dday_display(char *date)
{
	long long	day;

	day = getday(date);
	if (day == 0)
		printf("TODAY");
	else if (day > 0)
	{
		if (day == 1)
			printf("TOMORROW");
		else if (day < 8)
			printf("D-%lld", day);
		else
			printf("%s", date);
	}
	else if (day < 0)
	{
		if (day == -1)
			printf("YESTERDAY");
		else
		{
			day = day * (-1);
			printf("%lld days ago", day);
		}
	}
}

int 		callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    NotUsed = 0;
	size_t		len_s;
	long long	day;
   
	for (int i = 0; i < argc; i++) 
	{
		len_s = ft_strlen(azColName[i]);
		
		if (argv[i])
		{
			if (!ft_strncmp(azColName[i], "rowid", len_s))
			{
				printf("%-3s\t", argv[i]);
			}
			else if (!ft_strncmp(azColName[i], "complete", len_s))
			{
				if (argv[i] == "1")
					printf("[✓]  \t");
				else
					printf("[ ]  \t");
			}
			else if (!ft_strncmp(azColName[i], "title", len_s))
				printf("%-35s\t", argv[i]);
			else if (!ft_strncmp(azColName[i], "due", len_s))
			{
				dday_display(argv[i]);				
			}
		}
	}
	printf("\n");
    return (0);
}

void 		print_retrive_err(char **err_msg)
{
	fprintf(stderr, "Failed to select data\n");
    fprintf(stderr, "SQL error: %s\n", *err_msg);

    sqlite3_free(*err_msg);
}

int			main(void)
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
**	get path about cmdo.db
*/

	db_path = ft_strjoin(user_pw->pw_dir, "/.local/bin/cmdo.db");
	print_status((rc = sqlite3_open(db_path, &db)));

/*
**	http://zetcode.com/db/sqlitec/
*/
	
	if (!rc)
	{
		char *sql = "SELECT ROWID, complete, title, due FROM todo_list";
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

