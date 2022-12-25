package com.PICTBank.Services;

public class WithdrawLimitExceeded extends Exception
{
    @Override
    public String getMessage() {
        return "You cant withdraw amount greater than 1 lakh";

    }
}
