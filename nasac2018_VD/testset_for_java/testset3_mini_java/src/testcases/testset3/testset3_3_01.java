package testcases.testset3;

import testcasesupport.*;

public class testset3_3_01 extends AbstractTestCase
{
    public void foo_bar() throws Throwable
    {

        int[] intArray = new int[10];
        int i = 0;

        
        while (i <= intArray.length)
        {
            IO.writeLine("intArray[" + i + "] = " + (intArray[i] = i));
            i++;
        }

    }

    public void good() throws Throwable
    {
        good1();
    }

    private void good1() throws Throwable
    {

        int[] intArray = new int[10];
        int i = 0;

        
        while (i < intArray.length)
        {
            IO.writeLine("intArray[" + i + "] = " + (intArray[i] = i));
            i++;
        }

    }

    public static void main(String[] args) throws ClassNotFoundException,
           InstantiationException, IllegalAccessException
    {
        mainFromParent(args);
    }
}

