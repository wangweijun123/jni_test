package com.example.wangweijun.jni_test;

public class HelloWorld {

    static {
        System.loadLibrary("hello_jni");
    }

    public static native String helloWorld();

    public static native int addStaticMethod(int x, int y);

    public native int add(int x, int y);

    public native int[] arrElementsIncrease(int[] intArray);

    public native String sayHelloInc(String input);

    public native String strAppend(String contentStr);
}
