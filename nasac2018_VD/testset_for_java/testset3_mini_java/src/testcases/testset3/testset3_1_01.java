package testcases.testset3;

import testcasesupport.*;

public class testset3_1_01 extends AbstractTestCase
{
    public void foo_bar() throws Throwable
    {

        int[] intArray = new int[10];
        int i = 0;

        do
        {
            IO.writeLine("intArray[" + i + "] = " + (intArray[i] = i));
            i++;
        }
        while (i <= intArray.length);   

    }

    public void good() throws Throwable
    {
        good1();
    }

    private void good1() throws Throwable
    {

        int[] intArray = new int[10];
        int i = 0;

        do
        {
            IO.writeLine("intArray[" + i + "] = " + (intArray[i] = i));
            i++;
        }
        while (i < intArray.length);   

    }

    public static void main(String[] args) throws ClassNotFoundException,
           InstantiationException, IllegalAccessException
    {
        mainFromParent(args);
    }
}

