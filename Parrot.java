import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Random;

public class Parrot {

    private static Random random = new Random();
    private LinkedList<String> phrases;

    Parrot(LinkedList<String> _phrases) {
        this.phrases = _phrases;
    }

    public void addPhrase(String newPhrase) {
        this.phrases.add(newPhrase);
    }

    public void addPhrases(LinkedList<String> newPhrases) {
        this.phrases.addAll(newPhrases);
    }

    public void say() {
        System.out.println(this.phrases.get(random.nextInt(this.phrases.size())));
    }

    public void say(int repeatCount) {
        for (int i = 0; Integer.compareUnsigned(i, repeatCount) < 0; ++i)
            System.out.println(this.phrases.get(random.nextInt(this.phrases.size())));
    }

    public static void main(String[] args) {
        var parrot = new Parrot(new LinkedList<String>(Arrays.asList("Helo World!", "a", "b")));
        // parrot.say(5);
        parrot.addPhrases(new LinkedList<String>(Arrays.asList("c", "d")));
        parrot.say(5);
    }
}
