package Controller.Exceptions;

public class InvalidInput extends Exception {

    private String msg;

    public InvalidInput(String msg) {
        this.msg = msg;
    }

    public String getMessage() {
        return msg;
    }
}
