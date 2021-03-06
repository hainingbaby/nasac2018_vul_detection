package testcases.testset2.s02;
import testcasesupport.*;

import javax.servlet.http.*;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.net.URL;
import java.net.URLConnection;

import java.util.logging.Level;

public class testset2_22b
{
    public String foo_barSource(HttpServletRequest request, HttpServletResponse response) throws Throwable
    {
        String data;

        if (testset2_22a.foo_barPublicStatic)
        {
            data = ""; 
            
            {
                URLConnection urlConnection = (new URL("http://www.example.org/")).openConnection();
                BufferedReader readerBuffered = null;
                InputStreamReader readerInputStream = null;
                try
                {
                    readerInputStream = new InputStreamReader(urlConnection.getInputStream(), "UTF-8");
                    readerBuffered = new BufferedReader(readerInputStream);
                    
                    

                    data = readerBuffered.readLine();
                }
                catch (IOException exceptIO)
                {
                    IO.logger.log(Level.WARNING, "Error with stream reading", exceptIO);
                }
                finally
                {
                    
                    try
                    {
                        if (readerBuffered != null)
                        {
                            readerBuffered.close();
                        }
                    }
                    catch (IOException exceptIO)
                    {
                        IO.logger.log(Level.WARNING, "Error closing BufferedReader", exceptIO);
                    }

                    try
                    {
                        if (readerInputStream != null)
                        {
                            readerInputStream.close();
                        }
                    }
                    catch (IOException exceptIO)
                    {
                        IO.logger.log(Level.WARNING, "Error closing InputStreamReader", exceptIO);
                    }
                }
            }
        }
        else
        {
            

            data = null;
        }
        return data;
    }

    
    public String cwe_foo1Source(HttpServletRequest request, HttpServletResponse response) throws Throwable
    {
        String data;

        if (testset2_22a.cwe_foo1PublicStatic)
        {
            

            data = null;
        }
        else
        {

            
            data = "foo";

        }

        return data;
    }

    
    public String cwe_foo2Source(HttpServletRequest request, HttpServletResponse response) throws Throwable
    {
        String data;

        if (testset2_22a.cwe_foo2PublicStatic)
        {
            
            data = "foo";
        }
        else
        {
            

            data = null;
        }

        return data;
    }
}
