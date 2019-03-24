package testcases.testset1;

import testcasesupport.*;

import javax.servlet.http.*;

public class testset1_1_22a extends AbstractTestCase
{
    

    public static boolean foo_barPublicStatic = false;

    public void foo_bar() throws Throwable
    {
        String data;

        foo_barPublicStatic = true;
        data = (new testset1_1_22b()).foo_barSource();

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

    

    public static boolean cwe_foo1PublicStatic = false;
    public static boolean cwe_foo2PublicStatic = false;

    public void good() throws Throwable
    {
        cwe_foo1();
        cwe_foo2();
    }

    
    private void cwe_foo1() throws Throwable
    {
        String data;

        cwe_foo1PublicStatic = false;
        data = (new testset1_1_22b()).cwe_foo1Source();

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

    
    private void cwe_foo2() throws Throwable
    {
        String data;

        cwe_foo2PublicStatic = true;
        data = (new testset1_1_22b()).cwe_foo2Source();

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
