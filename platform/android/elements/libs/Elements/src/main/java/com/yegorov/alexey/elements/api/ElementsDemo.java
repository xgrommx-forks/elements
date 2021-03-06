package com.yegorov.alexey.elements.api;

public class ElementsDemo
{
    static
    {
        System.loadLibrary("elements");
    }

    public static native int create();
    public static native boolean startup(int id, int width, int height);
    public static native boolean destroy(int id);
    public static native boolean touch(int id, float x, float y, int action, int finger);
    public static native boolean rotation(int id, float x, float y, float z);
    public static native boolean render(int id);
}
