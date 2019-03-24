package testcases.testset2.s02;
import testcasesupport.*;

import javax.servlet.http.*;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.net.URL;
import java.net.URLConnection;

import java.util.logging.Level;

public class testset2_21 extends AbstractTestCaseServlet
{
    
    private boolean foo_barPrivate = false;

    public void foo_bar(HttpServletRequest request, HttpServletResponse response) throws Throwable
    {
        String data;

        foo_barPrivate = true;
        data = foo_bar_source(request, response);

        if (data != null)
        {
            
            response.getWriter().println("<br>foo_bar(): data = " + data);
        }

    }

    private String foo_bar_source(HttpServletRequest request, HttpServletResponse response) throws Throwable
    {
        String data;

        if (foo_barPrivate)
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

    
    private boolean cwe_foo1_private = false;
    private boolean cwe_foo2_private = false;

    public void good(HttpServletRequest request, HttpServletResponse response) throws Throwable
    {
        cwe_foo1(request, response);
        cwe_foo2(request, response);
    }

    
    private void cwe_foo1(HttpServletRequest request, HttpServletResponse response) throws Throwable
    {
        String data;

        cwe_foo1_private = false;
        data = cwe_foo1_source(request, response);

        if (data != null)
        {
            
            response.getWriter().println("<br>foo_bar(): data = " + data);
        }

    }

    private String cwe_foo1_source(HttpServletRequest request, HttpServletResponse response) throws Throwable
    {
        String data = null;

        if (cwe_foo1_private)
        {
            

            data = null;
        }
        else
        {

            
            data = "foo";

        }

        return data;
    }

    
    private void cwe_foo2(HttpServletRequest request, HttpServletResponse response) throws Throwable
    {
        String data;

        cwe_foo2_private = true;
        data = cwe_foo2_source(request, response);

        if (data != null)
        {
            
            response.getWriter().println("<br>foo_bar(): data = " + data);
        }

    }

    private String cwe_foo2_source(HttpServletRequest request, HttpServletResponse response) throws Throwable
    {
        String data = null;

        if (cwe_foo2_private)
        {
            
            data = "foo";
        }
        else
        {
            

            data = null;
        }

        return data;
    }

    public static void main(String[] args) throws ClassNotFoundException,
           InstantiationException, IllegalAccessException
    {
        mainFromParent(args);
    }

}
