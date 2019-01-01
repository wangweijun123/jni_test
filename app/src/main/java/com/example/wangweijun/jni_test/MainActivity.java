package com.example.wangweijun.jni_test;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;

public class MainActivity extends AppCompatActivity {
    HelloWorld helloWorld = new HelloWorld();
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        // Example of a call to a native method
//        TextView tv = (TextView) findViewById(R.id.sample_text);
//        tv.setText(stringFromJNI());
    }


    public void helloWorldFromc(View view) {
        Log.i("wangweijun", HelloWorld.helloWorld());
    }

    public void addStaticFromCReturnJava(View view) {
        Log.i("wangweijun", "addStaticFromCReturnJava:"+HelloWorld.addStaticMethod(1,2));
    }

    public void addFromCReturnJava(View view) {
        Log.i("wangweijun", "result:"+helloWorld.add(1,2));
    }

    public void sayHelloInc(View view) {
        Log.i("wangweijun", "result:"+helloWorld.sayHelloInc("abcde"));
    }

    public void arrElementsIncrease(View view) {
//        Log.i("wangweijun", helloWorld.strAppend("abc"));

        int arr[] = new int[]{1,2,3,4,5};
        arr = helloWorld.arrElementsIncrease(arr);
        for (int i = 0; i < arr.length; i++) {
            Log.i("wangweijun", "result:"+arr[i]);
        }

    }
}
