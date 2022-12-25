package com.PICTBank.Services;

public class InsufficientBalance extends Exception
{
    @Override
    public String getMessage() {
        return "Insufficient account balance to withdraw amount";
    }
}
