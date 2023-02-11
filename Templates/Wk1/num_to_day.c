#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

char *num_to_day(int n);

int main(int argc, char *argv[]) {
    /**
     * Recall that strcmp(str1, str2) returns
     * 0 if str1 and str2 are the same
     * -1 if str1 is lexicographically before str2
     * 1 if str1 is lexicographically after str2
     */
    assert(strcmp(num_to_day(0), "Sun") == 0);
    assert(strcmp(num_to_day(1), "Mon") == 0);
    assert(strcmp(num_to_day(2), "Tue") == 0);
    assert(strcmp(num_to_day(3), "Wed") == 0);
    assert(strcmp(num_to_day(4), "Thu") == 0);
    assert(strcmp(num_to_day(5), "Fri") == 0);
    assert(strcmp(num_to_day(6), "Sat") == 0);
    
    printf("Tests passed\n");
}

char *num_to_day(int n) {
	assert(0 <= n && n <= 6);
	char *day;
	if (n == 0) {
		day = "Sun";
	} else if (n == 1) {
		day = "Mon";
	} else if (n == 2) {
		day = "Tue";
	} else if (n == 3) {
		day = "Wed";
	} else if (n == 4) {
		day = "Thu";
	} else if (n == 5) {
		day = "Fri";
	} else if (n == 6) {
		day = "Sat";
	}
	return day;
}