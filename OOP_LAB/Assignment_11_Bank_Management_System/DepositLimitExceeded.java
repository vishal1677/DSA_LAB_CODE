package com.PICTBank.Services;

public class DepositLimitExceeded extends Exception
{
    @Override
    public String getMessage() {
        return "You can't deposit amount greater than 1 lakh via online mode";
    }
}
