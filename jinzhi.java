public class jinzhi
{
    public static int parseInt(String str)
    {
        char ch = str.charAt(0);
        int value = 0,i=0,sign = 1,radix = 10;
        if(ch >= '1' && ch<='9' || ch == '+' || ch == '-'||ch == '0' && ch.length() == 1)
        {
            if (ch=='+'||ch == '-')
                i++;
            sign = ch=='-'?-1:1;
        }
        else if(ch=='0'&&str.length()>1&&str.charAt(1)!='x')
        {
            radix = 8;
            i++;
        }
        else if (ch=='0'&&str.length()>2&&str.charAt(1)=='x')
        {
            radix = 16;
            i++;
        }
        else
            throw new NumberFormatException("进制整数不能识别'"+ch+"\'字符");
        
        while(i<str.length())
        {
            ch = str.charAt(i++);
            if(ch>='0'&&ch-'0'<radix)
            {
                value = value*radix+ch-'0';
            }
            else if(radix == 16&&ch>='a'&&ch<='f')
                value = value*radix+ch-'a'+10;
            else if(radix == 16&&ch>='A'&&ch<='B')
                value = value*radix+ch-'A'+10;
            else
                throw new NumberFormatException("radix can't show"+ch);
        }
        return value*sign;
    }

    public static String toString(int value,int radix) {
        if(radix == 10)
            return value+"";
        if (radix == 2||radix == 4||radix==8||radix==16)
        {
            int mask,n=0;
            for (mask=radix-1;mask>0;mask>>>=1)
                n++;
            mask = radix - 1;
            char buffer[] = new char[(int)(32.0/n+0.5)];
            for (int i=buffer.length-1;i>=0;i--)
            {
                int bit = value & mask;
                buffer[i] = (char)(bit<=9?bit+'0':bit + 'a' - 10);
                value>>>=n;
            }
            if(radix == 2)
                return new String(buffer);
            if(radix == 8)
                return "0"+new String(buffer);
            return "0x" + new String(buffer);
        }
        throw new IllegalArgumentException("radix can't show"+radix);
    }

    public static void main(String[] args)
    {
        int a = yanghui.parseInt("0x908afd");
        System.out.println(a); 
        System.out.println(yanghui.toString(a,16));
    }
}



