#if !defined(CODE_MANUP_H)
#define CODE_MANUP_H

    // This function will fnd the occurence of substr in the main string.
    int find_str(char *string, char *substring)
    {
        int i, j, l1, l2;
        int count = 0;
        l1 = strlen(string);
        l2 = strlen(substring);

        for (i = 0; i < l1 - l2 + 1; i++)
        {
            if (strstr(string + i, substring) == string + i)
            {
                count++;
                i = i + l2 - 1;
            }
        }
        return count;
    }

    /**
     * @brief This function will replace the substr in a main string.
     *
     * @param s main str.
     * @param s1 old str to be replaced.
     * @param s2 new str shall be replaced.
     */
    void replace(char str[], char sub[], char nstr[])

    {

        int strLen, subLen, nstrLen;

        int i = 0, j, k;

        int flag = 0, start, end;

        strLen = strlen(str);

        subLen = strlen(sub);

        nstrLen = strlen(nstr);

        for (i = 0; i < strLen; i++)

        {

            flag = 0;

            start = i;

            for (j = 0; str[i] == sub[j]; j++, i++)

                if (j == subLen - 1)

                    flag = 1;

            end = i;

            if (flag == 0)

                i -= j;

            else
            {
                for (j = start; j < end; j++)

                {

                    for (k = start; k < strLen; k++)

                        str[k] = str[k + 1];

                    strLen--;

                    i--;
                }

                for (j = start; j < start + nstrLen; j++)

                {

                    for (k = strLen; k >= j; k--)

                        str[k + 1] = str[k];

                    str[j] = nstr[j - start];

                    strLen++;

                    i++;
                }
            }
        }
    }

#endif // CODE_MANUP_H
