package testcases.testset3;

import testcasesupport.*;

public class testset3_2_01 extends AbstractTestCase
{
    public void foo_bar() throws Throwable
    {

        int[] intArray = new int[10];

        
        for (int i = 0; i <= intArray.length; i++)
        {
            IO.writeLine("intArray[" + i + "] = " + (intArray[i] = i));
        }

    }

    public void good() throws Throwable
    {
        good1();
    }

    private void good1() throws Throwable
    {

        int[] intArray = new int[10];

        
        for (int i = 0; i < intArray.length; i++)
        {
            IO.writeLine("intArray[" + i + "] = " + (intArray[i] = i));
        }

    }

    public static void main(String[] args) throws ClassNotFoundException,
           InstantiationException, IllegalAccessException
    {
        mainFromParent(args);
    }
}

