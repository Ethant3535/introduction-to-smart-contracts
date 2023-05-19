public class IncorrectFileExtension extends RuntimeException {
    public IncorrectFileExtension(String message) {
        // construct the parent class (RuntimeException)
        // with the error message passed into this constructor
        super(message);
    }
}
