import java.lang.*;
import java.io.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import javax.swing.text.html.HTMLDocument.HTMLReader.IsindexAction;

class Check
{
    public Boolean CheckPerfect(int iNo)
    {
        int iCnt = 0;
        int iSum = 0;

        for(iCnt = 1; iCnt < iNo; iCnt++)
        {
            if(iNo % iCnt == 0)
            {
                iSum = iSum + iCnt;
            }
        }
        if(iSum == iNo)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

class Perfect
{
    public static void main(String arg[]) throws IOException
    {
        boolean bRet = false;

        InputStreamReader iobj = new InputStreamReader(System.in);
        BufferedReader bobj = new BufferedReader(iobj);

        System.out.println("Enter number : ");
        int iValue = Integer.parseInt(bobj.readLine());

        Check cobj = new Check();

        bRet = cobj.CheckPerfect(iValue);

        if(bRet == true)
        {
            System.out.println(iValue+ " is Perfect number");
        }
        else
        {
            System.out.println(iValue+ " is not a Perfect number");
        }


    }
}