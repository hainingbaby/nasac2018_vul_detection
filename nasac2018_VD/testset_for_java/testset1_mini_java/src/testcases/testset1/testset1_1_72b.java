package testcases.testset1;

import testcasesupport.*;
import java.util.Vector;

import javax.servlet.http.*;

public class testset1_1_72b
{
    public void foo_barSink(Vector<String> dataVector ) throws Throwable
    {
        String data = dataVector.remove(2);

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

    
    public void cwe_fooSink(Vector<String> dataVector ) throws Throwable
    {
        String data = dataVector.remove(2);

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
