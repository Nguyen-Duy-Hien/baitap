void reverse(char *s) {
    char *begin = s, *last = s + strlen(s) -1;

    while (begin < last) {
        swap(*begin, *last);
        begin++;
        last--;
    }
}