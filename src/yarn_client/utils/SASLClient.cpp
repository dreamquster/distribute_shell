#include "SASLClient.h"

#include <signal.h>
#include <stdio.h>
#include <termios.h>
#include <stdlib.h>
#define MAX_PASS_LEN 8




/* remove \r\n at end of the line */
static void chop(char *s)
{
	char *p;

	assert(s);
	p = s + strlen(s) - 1;
	if (p[0] == '\n') {
		*p-- = '\0';
	}
	if (p >= s && p[0] == '\r') {
		*p-- = '\0';
	}
}

int getrealm(void *context __attribute__((unused)), 
	int id,
	const char **availrealms,
	const char **result)
{
	static char buf[1024];

	/* Double-check the ID */
	if (id != SASL_CB_GETREALM) return SASL_BADPARAM;
	if (!result) return SASL_BADPARAM;

	printf("please choose a realm (available:");
	while (*availrealms) {
		printf(" %s", *availrealms);
		availrealms++;
	}
	printf("): ");

	fgets(buf, sizeof buf, stdin);
	chop(buf);
	*result = buf;

	return SASL_OK;
}

int simple(void *context __attribute__((unused)),
	int id,
	const char **result,
	unsigned *len)
{
	static char buf[1024];

	/* Double-check the connection */
	if (! result)
		return SASL_BADPARAM;

	switch (id) {
	case SASL_CB_USER:
		printf("please enter an authorization id: ");
		break;
	case SASL_CB_AUTHNAME:
		printf("please enter an authentication id: ");
		break;
	default:
		return SASL_BADPARAM;
	}

	fgets(buf, sizeof buf, stdin);
	chop(buf);
	*result = buf;
	if (len) *len = strlen(buf);

	return SASL_OK;
}


int getsecret(sasl_conn_t *conn,
	void *context __attribute__((unused)),
	int id,
	sasl_secret_t **psecret)
{
	char *password;
	size_t len;
	static sasl_secret_t *x;

	/* paranoia check */
	if (! conn || ! psecret || id != SASL_CB_PASS)
		return SASL_BADPARAM;

	password = "Password: ";
	if (! password)
		return SASL_FAIL;

	len = strlen(password);

	x = (sasl_secret_t *) realloc(x, sizeof(sasl_secret_t) + len);

	if (!x) {
		memset(password, 0, len);
		return SASL_NOMEM;
	}

	x->len = len;

	strcpy((char *)x->data, password);

	memset(password, 0, len);

	*psecret = x;
	return SASL_OK;
}

int getpath(void * context __attribute__((unused)),
	const char **path)
{
	*path = getenv("SASL_PATH");

	if (*path == NULL)
		*path = "/";

	return SASL_OK;
}


