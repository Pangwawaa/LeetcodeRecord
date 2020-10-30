/*
 * @lc app=leetcode.cn id=14 lang=c
 *
 * [14] 最长公共前缀
 */

// @lc code=start

char * longestCommonPrefix(char ** strs, int strsSize){
    
    int pos = 0;
    int temp = 0;
    int len = 0;

    if(!strsSize)
        return "";
    else if(strsSize == 1)
        return strs[0];
        
    
    for (int i = 0; i < strsSize; i++)
    {
        if(!strcmp(strs[i],""))
            return "";
        temp = strlen(strs[i]);
        len = len>temp?len:temp;
    }

    char *ret = malloc(len+1);
    //ret = malloc(len+1);
    //if(!rets)
        //return 0;

        
#if 0
    for (int i = 0; i < strsSize; i++)
    {
        int a = strcmp(strs[i],"");
        if(!a)
            return ret;
        else
            array[i] = strs[i];

    }

    while(*(array[0] + pos) != '\0' && *(array[1] + pos) != '\0' && *(array[2] + pos) != '\0')
    {
        if((*(array[0] + pos) != *(array[1] + pos)) ||
            (*(array[0] + pos) != *(array[2] + pos)))
        {
            if(pos)
            {
                *(ret + pos) = '\0';
                return ret;
            }
            else
            {
                return ret;
            }
        }
        else
        {
            *(ret + pos) = *(array[0] + pos);
            
        }
    
        pos++;
    }       
    *(ret + pos) = '\0';
    return ret;
#else
    while(pos < len)
    {
        for (int i = 0; i < strsSize-1; i++)
        {      
            if(*(strs[i]+pos) != *(strs[i+1]+pos))
            {
                if(pos)
                {
                    *(ret + pos) = '\0';
                    return ret;
                }
                else
                {
                    return "";
                }
            }
            
            *(ret + pos) = *(strs[i]+pos);
        }
        pos++;
    }

    *(ret + pos) = '\0';
    return ret;
#endif
}



// @lc code=end

