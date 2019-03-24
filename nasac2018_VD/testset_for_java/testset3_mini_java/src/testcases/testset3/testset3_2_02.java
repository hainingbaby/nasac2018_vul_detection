package testcases.testset3;

import testcasesupport.*;

public class testset3_2_02 extends AbstractTestCase
{
    public void foo_bar() throws Throwable
    {
        if (true)
        {
            int[] intArray = new int[10];
            
            for (int i = 0; i <= intArray.length; i++)
            {
                IO.writeLine("intArray[" + i + "] = " + (intArray[i] = i));
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

            
            for (int i = 0; i < intArray.length; i++)
            {
                IO.writeLine("intArray[" + i + "] = " + (intArray[i] = i));
            }

        }
    }

    
    private void good2() throws Throwable
    {
        if (true)
        {
            int[] intArray = new int[10];
            
            for (int i = 0; i < intArray.length; i++)
            {
                IO.writeLine("intArray[" + i + "] = " + (intArray[i] = i));
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
