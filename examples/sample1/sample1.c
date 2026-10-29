#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>

int main() {

    // 1. Configure connection string
    const char *conninfo =
      "host=localhost "
      "port=5432 "
      "dbname=book "
      "user=myuser "
      "password=mypasswd";

    // 2. Establish connection
    PGconn *conn = PQconnectdb(conninfo);

    if (PQstatus(conn) != CONNECTION_OK) {
        fprintf(stderr, "Connection error: %s\n", 
			PQerrorMessage(conn));
        PQfinish(conn);
        exit(1);
    }

    printf("PostgreSQL connection Ok!\n");

    // 3. Execute SELECT over table interveners.employees
    const char *query = "SELECT "
	                "  id, intervener_name "
                        "FROM interveners.employee";
    PGresult *res = PQexec(conn, query);

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        fprintf(stderr, "Falha na query: %s\n", 
			PQerrorMessage(conn));
        PQclear(res);
        PQfinish(conn);
        exit(1);
    }

    // 4. Get rows and columns count
    int rows = PQntuples(res);
    int cols = PQnfields(res);

    printf("\nEmployee List (%d found)\n", rows);

    // 5. Iterate over results and print
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%s : %s | ", PQfname(res, j), 
			    PQgetvalue(res, i, j));
        }
        printf("\n");
    }

    // 6. clear memory and close connection
    PQclear(res);
    PQfinish(conn);

    return 0;
}
