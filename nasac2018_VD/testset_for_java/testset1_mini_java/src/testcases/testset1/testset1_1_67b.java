package testcases.testset1;

import testcasesupport.*;

import javax.servlet.http.*;

public class testset1_1_67b
{
    public void foo_barSink(testset1_1_67a.Container dataContainer ) throws Throwable
    {
        String data = dataContainer.containerOne;

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

    
    public void cwe_fooSink(testset1_1_67a.Container dataContainer ) throws Throwable
    {
        String data = dataContainer.containerOne;

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
}
