package Controller.Exceptions;

public class NotFoundItem extends Exception {

    private String msgString;

    public NotFoundItem(String msg) {
        this.msgString = msg;
    }

    public String getMessage() {
        return msgString;
    }
}
