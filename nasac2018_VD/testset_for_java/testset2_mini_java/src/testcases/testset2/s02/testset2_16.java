package testcases.testset2.s02;
import testcasesupport.*;

import javax.servlet.http.*;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.net.URL;
import java.net.URLConnection;

import java.util.logging.Level;

public class testset2_16 extends AbstractTestCaseServlet
{
    
    public void foo_bar(HttpServletRequest request, HttpServletResponse response) throws Throwable
    {
        String data;

        while (true)
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
            break;
        }

        if (data != null)
        {
            
            response.getWriter().println("<br>foo_bar(): data = " + data);
        }

    }

    
    private void cwe_foo(HttpServletRequest request, HttpServletResponse response) throws Throwable
    {
        String data;

        while (true)
        {
            
            data = "foo";
            break;
        }

        if (data != null)
        {
            
            response.getWriter().println("<br>foo_bar(): data = " + data);
        }

    }

    public void good(HttpServletRequest request, HttpServletResponse response) throws Throwable
    {
        cwe_foo(request, response);
    }

    public static void main(String[] args) throws ClassNotFoundException,
           InstantiationException, IllegalAccessException
    {
        mainFromParent(args);
    }
}
