package testcases.testset3;

import testcasesupport.*;

public class testset3_3_02 extends AbstractTestCase
{
    public void foo_bar() throws Throwable
    {
        if (true)
        {
            int[] intArray = new int[10];
            int i = 0;
            
            while (i <= intArray.length)
            {
                IO.writeLine("intArray[" + i + "] = " + (intArray[i] = i));
                i++;
            }
        }
    }

    
    private void good1() throws Throwable
    {
        if (false)
        {
            
            IO.writeLine("Benign, fixed string");
        }
        else
        {

            int[] intArray = new int[10];
            int i = 0;

            
            while (i < intArray.length)
            {
                IO.writeLine("intArray[" + i + "] = " + (intArray[i] = i));
                i++;
            }

        }
    }

    
    private void good2() throws Throwable
    {
        if (true)
        {
            int[] intArray = new int[10];
            int i = 0;
            
            while (i < intArray.length)
            {
                IO.writeLine("intArray[" + i + "] = " + (intArray[i] = i));
                i++;
            }
        }
    }

    public void good() throws Throwable
    {
        good1();
        good2();
    }

    public static void main(String[] args) throws ClassNotFoundException,
           InstantiationException, IllegalAccessException
    {
        mainFromParent(args);
    }
}
