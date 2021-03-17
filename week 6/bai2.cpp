void rFilter(char *s) {
    char *last = s + strlen(s) -1;

    while (last>=s && !(*(last)>='a' && *(last)<='z' || *(last)>='A' && *(last)<='Z')) {
        *(last) = '_';
        last--;
    }
}