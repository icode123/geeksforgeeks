//http://www.geeksforgeeks.org/reverse-words-in-a-given-string/
//input:“i like this program very much”, output:“much very program this like i”;

//两次反转，时间复杂度：O(n)；
//注意开头的空格和单词之间的多个空格问题；
void reverse(char *begin, char *end)
{
   char tmp;
   while (begin<end)
   {
     tmp=*begin;
	   *begin++=*end;
	   *end--=tmp
   }
}

void reverseWords(char *s)
{
	char *word_begin=NULL;
	char *tmp=s;
	while (*tmp!='\0')
	{
		if (word_begin==NULL && *tmp!=' ')
		{
			word_begin=tmp;
		}
		if (word_begin && (*(tmp+1)==' '||*(tmp+1)=='\0'))
		{
			reverse(word_begin,tmp);
			word_begin=NULL;
		}
		tmp++;
	}
	reverse(s,tmp-1);
}


