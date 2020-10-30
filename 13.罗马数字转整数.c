/*
 * @lc app=leetcode.cn id=13 lang=c
 *
 * [13] 罗马数字转整数
 */

// @lc code=start


int romanToInt(char * s){

    char *str = s;
    //局部变量初值不是0
    int ret = 0;
    int num = 0;
    int val = 0;

    if((*str == '\0') || (!str))
        return 0;

    while(*str != '\0')
    {
        switch (*str)
        {
        case 'I':
            if(*(str+1) == 'V')
                num = 4;
            else if(*(str+1) == 'X')
                num = 9;
            else 
                val = 1;
            break;

        case 'X':
            if(*(str+1) == 'L')
                num = 40;
            else if(*(str+1) == 'C')
                num = 90;
            else
                val = 10;
            break;

        case 'C':
            if(*(str+1) == 'D')
                num = 400;
            else if(*(str+1) == 'M')
                num = 900;
            else
                val = 100;
            break;
            
        case 'V':
            val = 5;
            break;

        case 'L':
            val = 50;
            break;
        
        case 'D':
            val = 500;
            break;

        case 'M':
            val = 1000;
            break;
            
        default:
            break;
        }

        if (num)
        {
            str += 2;
            ret += num;
            num = 0;
        }
        else
        {
            str += 1;
            ret += val;
        }
    }

    return ret;

}


// @lc code=end

