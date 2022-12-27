#include <stdio.h>
#include <string.h>

void sub_string_find1() {
	char needle[] = "heart";
	char haystack[] = "Get to the heart of the matter";
	char *found;

	found = strstr(haystack, needle);
	if (found == NULL)
		printf("The string \"%s\" was not found in \"%s\".\n", needle,
				haystack);
	else
		printf("The string \"%s\" was found at offset %ld in \"%s\".\n", needle,
				found - haystack, haystack);
}

void remove_word() {
	char sentence[100], word[50], temp[100];
	printf("Enter long string: ");
	scanf("%[^\n]s", sentence);
	getchar();
	printf("Enter substring to remove: ");
	scanf("%[^\n]s", word);

	char *str = strstr(sentence, word);
	if (str != NULL) {
		*str = '\0';
		str += strnlen(word, 50);
		strncpy(temp, str, 100);
		strncat(sentence, temp, 100);
		printf("Removing the word: \"%s\"\n", sentence);
	} else {
		printf("\"%s\" not found in \"%s\"!\n", word, sentence);
	}
}

void string_copy() {
	char r[] = "red";
	char g[] = "green";
	char b[] = "blue";

	if (strcmp(r, "blue") == 0)
		printf("%s compares with \"blue\"\n", r);
	if (strcmp(g, "blue") == 0)
		printf("%s compares with \"blue\"\n", g);
	if (strcmp(b, "blue") == 0)
		printf("%s compares with \"blue\"\n", b);

	char string[] = "Hello, you happy planet.";
	int len;

	len = strlen(string);
	printf("The string \"%s\" is %d characters long.\n", string, len);

	char original[] = "Am I the original?";
	char duplicate[] = "Overwritten";

	printf("Here is the original string: %s\n", original);
	printf("Here is the duplicate string: %s\n", duplicate);
	strcpy(duplicate, original);
	printf("Here is the duplicate: %s\n", duplicate);

	char fullname[64];
	char firstname[32];
	char lastname[32];

	printf("Your first name: ");
	fgets(firstname, 32, stdin);
	printf("Your last name: ");
	fgets(lastname, 32, stdin);

	strcpy(fullname, firstname);
	strcat(fullname, lastname);
	printf("%s", fullname);

	char original1[] = "Am I the original?";
	char duplicate1[32];

	printf("Here is the original string: %s\n", original1);
	strcpy(duplicate1, original1);
	printf("Here is the duplicate: %s\n", duplicate1);

	char needle[] = "heart";
	char haystack[] = "Get to the heart of the matter";
	char *found;

	found = strstr(haystack, needle);
	if (found == NULL)
		printf("The string \"%s\" was not found in \"%s\".\n", needle,
				haystack);
	else
		printf("The string \"%s\" was found in \"%s\".\n", needle, haystack);

	char country[15] = "United Kingdom";

	printf("\n\n");
	printf("*123456789012345*\n");
	printf(" --------------- \n");

	printf("%15s\n", country);
	printf("%5s\n", country);
	printf("%15.6s\n", country);
	printf("%-15.6s\n", country);
	printf("%15.0s\n", country);
	printf("%.3s\n", country);
	printf("%s\n", country);
	printf("---------------- \n");
}

void ascii_characters() {
	char c;
	printf("\n\n");
	for (c = 65; c <= 122; c = c + 1) {
		if (c > 90 && c < 97)
			continue;
		printf("|%4d - %c ", c, c);
	}
	printf("|\n");
}
void reading_strings() {
	char line[81], character;
	int c;
	c = 0;
	printf("Enter text. Press <Return> at end\n");
	do {
		character = getchar();
		line[c] = character;
		c++;
	} while (character != '\n');
	c = c - 1;
	line[c] = '\0';
	printf("%s\n", line);
}

void concatenate() {
	int i, j, k;
	char first_name[10] = { "VISWANATH" };
	char second_name[10] = { "PRATAP" };
	char last_name[10] = { "SINGH" };
	char name[30];
	/* Copy first_name into name */
	for (i = 0; first_name[i] != '\0'; i++)
		name[i] = first_name[i];
	/* End first_name with a space */
	name[i] = ' ';
	/* Copy second_name into name */
	for (j = 0; second_name[j] != '\0'; j++)
		name[i + j + 1] = second_name[j];
	/* End second_name with a space */
	name[i + j + 1] = ' ';
	/* Copy last_name into name */
	for (k = 0; last_name[k] != '\0'; k++)
		name[i + j + k + 2] = last_name[k];
	/* End name with a null character */
	name[i + j + k + 2] = '\0';
	printf("\n\n");
	printf("%s\n", name);
}

void copying_strings_char_wise() {
	char string1[80], string2[80];
	int i;

	printf("Enter a string \n");
	printf("?");

	scanf("%s", string2);

	for (i = 0; string2[i] != '\0'; i++)
		string1[i] = string2[i];

	string1[i] = '\0';

	printf("\n");
	printf("%s\n", string1);
	printf("Number of characters = %d\n", i);
}

#define ITEMS   5
#define MAXCHAR 20
void sorting_strings() {
	char string[ITEMS][MAXCHAR], dummy[MAXCHAR];
	int i = 0, j = 0;
	/* Reading the list */
	printf("Enter names of %d items \n", ITEMS);
	while (i < ITEMS)
		scanf("%s", string[i++]);
	/* Sorting begins */
	for (i = 1; i < ITEMS; i++) /* Outer loop begins */
	{
		for (j = 1; j <= ITEMS - i; j++) /*Inner loop begins*/
		{
			if (strcmp(string[j - 1], string[j]) > 0) { /* Exchange of contents */
				strcpy(dummy, string[j - 1]);
				strcpy(string[j - 1], string[j]);
				strcpy(string[j], dummy);
			}
		} /* Inner loop ends */
	} /* Outer loop ends */
	/* Sorting completed */
	printf("\nAlphabetical list \n\n");
	for (i = 0; i < ITEMS; i++)
		printf("%s\n", string[i]);
}

void string_functions() {
	char s1[20], s2[20], s3[20];
	int x, l1, l2, l3;
	printf("\n\nEnter two string constants \n");
	printf("?");
	scanf("%s %s", s1, s2);
	/* comparing s1 and s2 */
	x = strcmp(s1, s2);
	if (x != 0) {
		printf("\n\nStrings are not equal \n");
		strcat(s1, s2); /* joining s1 and s2 */
	} else
		printf("\n\nStrings are equal \n");
	/* copying s1 to s3 */
	strcpy(s3, s1);
	/* Finding length of strings */
	l1 = strlen(s1);
	l2 = strlen(s2);
	l3 = strlen(s3);
	/* output */
	printf("\ns1 = %s\t length = %d characters\n", s1, l1);
	printf("s2 = %s\t length = %d characters\n", s2, l2);
	printf("s3 = %s\t length = %d characters\n", s3, l3);
}

void string_operations() {
	const static int maxBuf = 128;
	const char *s1 = "String one";
	const char *s2 = "String two";
	char sd1[maxBuf];
	char sd2[maxBuf];
	int i = 0;
	char c = 0;
	char *cp = NULL;

	printf("s1 is %s; s2 is %s\n", s1, s2);
	printf("sizeof sd1 is %ld; sizeof sd2 is %ld\n", sizeof sd1, sizeof sd2);

	strncpy(sd1, s1, maxBuf);	// strncpy -- copy a string
	printf("sd1 is %s\n", sd1);
	strncpy(sd2, s2, maxBuf);
	printf("sd2 is %s\n", sd2);

	strncat(sd1, " - ", maxBuf - strlen(sd1) - 1);// strncat -- concatenate string
	strncat(sd1, s2, maxBuf - strlen(sd1) - 1);
	printf("sd1 is %s\n", sd1);

	printf("length of sd1 is %ld\n", strlen(sd1));// strlen -- get length of string
	printf("length of sd2 is %ld\n", strlen(sd2));

	i = strcmp(sd1, sd2);	// strcmp -- compare strings
	printf("sd1 %s sd2 (%d)\n", (i == 0) ? "==" : "!=", i);
	i = strcmp(sd2, s2);
	printf("sd2 %s s2 (%d)\n", (i == 0) ? "==" : "!=", i);

	c = 'g';
	cp = strchr(sd1, c);	// strchr -- find a char in string
	printf("Did we find a '%c' in sd1? %s\n", c, cp ? "yes" : "no");
	if (cp)
		printf("The first '%c' in sd1 is at position %ld\n", c, cp - sd1);

	cp = strstr(sd1, s2);	// strstr -- find a string in string
	printf("Did we find '%s' in sd1? %s\n", s2, cp ? "yes" : "no");
	if (cp)
		printf("The first '%s' in sd1 is at position %ld\n", s2, cp - sd1);
}

void declarations() {
	char password[] = "spatula";
	char sonnet18[] =
			"Shall I compare thee to a summer's day?\
	 Thou art more lovely and more temperate:\
	 Rough winds do shake the darling buds of May,\
	 And summer's lease hath all too short a date:\
	 Sometime too hot the eye of heaven shines,\
	 And often is his gold complexion dimmed;\
	 And every fair from fair sometime declines,\
	 By chance, or nature's changing course, untrimmed:\
	 But thy eternal summer shall not fade,\
	 Nor lose possession of that fair thou ow'st;\
	 Nor shall Death brag thou wander'st in his shade\
	 When in eternal lines to time thou grow'st:\
	 So long as men can breathe or eyes can see,\
	 So long lives this, and this gives life to thee.";

	printf("The password is %s\n", password);
	puts(password);
	puts(sonnet18);
}

int main() {
	printf("Hello, Earth!");
	printf("\n");
	printf("Hello, Earth!\n");
	printf("%s", "Hello, Moon!\n");

	ascii_characters();
	reading_strings();
	concatenate();
	copying_strings_char_wise();
	string_formatted_output();
	sorting_strings();
	string_functions();

	string_compare();
	string_length();
	sub_string_find1();
	sub_string_find2();

	string_operations();
	remove_word();

	string_copy();

	char string1[] = "I'm such a handsome program!\n";
	int a1;

	a1 = 0;
	while (string1[a1] != '\0') {
		putchar(string1[a1]);
		a1++;
	}

	char string2[] = "I'm such a handsome program!\n";
	int a2;

	a2 = 0;
	while (putchar(string2[a2]) != '\0') {
		a2++;
	}

	char string3[] = "I'm such a handsome program!\n";
	int a3;

	a3 = 0;
	while (putchar(string3[a3])) {
		a3++;
	}

	char string4[] = "I'm such a handsome program!\n";
	int a4;

	a4 = 0;
	while (putchar(string4[a4++]))
		;
	return 0;
}
