package testcases.testset1;

import testcasesupport.*;

import javax.servlet.http.*;

public class testset1_1_61a extends AbstractTestCase
{
    public void foo_bar() throws Throwable
    {
        String data = (new testset1_1_61b()).foo_barSource();

        String osCommand;
        if(System.getProperty("os.name").toLowerCase().indexOf("win") >= 0)
        {
            
            osCommand = "c:\\WINDOWS\\SYSTEM32\\cmd.exe /c dir ";
        }
        else
        {
            
            osCommand = "/bin/ls ";
        }

        
        Process process = Runtime.getRuntime().exec(osCommand + data);
        process.waitFor();

    }

    public void good() throws Throwable
    {
        cwe_foo();
    }

    
    private void cwe_foo() throws Throwable
    {
        String data = (new testset1_1_61b()).cwe_fooSource();

        String osCommand;
        if(System.getProperty("os.name").toLowerCase().indexOf("win") >= 0)
        {
            
            osCommand = "c:\\WINDOWS\\SYSTEM32\\cmd.exe /c dir ";
        }
        else
        {
            
            osCommand = "/bin/ls ";
        }

        
        Process process = Runtime.getRuntime().exec(osCommand + data);
        process.waitFor();

    }

    public static void main(String[] args) throws ClassNotFoundException,
           InstantiationException, IllegalAccessException
    {
        mainFromParent(args);
    }
}
