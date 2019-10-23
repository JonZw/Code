public class Pokemon
{
    private String name;
    private Type type;
    private int number;
    private static int nextNumber = 0;
    // Felix
    private Trainer trainer;

    public Pokemon(String name, Type type)
    {
        this.name = name;
        this.type = type;
        this.number = nextNumber;

        nextNumber += 1;
    }

    public void setName(String name)
    {
        this.name = name;
    }

    public String getName()
    {
        /*
        "this" liefert eine Referenz auf das Objekt, 
        von dem aus die Operation aufgerufen wird.
        Die kann z.B. zur Vermeiden von Namens-
        konflikten verwendet werden 
        (siehe z.B. im Constructor oben).
        */

        return this.name;
    }

    public Type getType()
    {
        return this.type;
    }

    public void setType(Type type)
    {
        this.type = type;
    }

    public void setTrainer(Trainer newTrainer)
    {
        trainer=newTrainer;
    }

    public final Trainer getTrainer()
    {
        return trainer;
    }


    public String toString()
    {
        String string = "";
        string += "Name: " + this.name;
        string += "\nType: " + type;
        string += "\nNumber: " + number;
        string += "\nTrainer: " + trainer;

        return string;
    }

    public static void main(String[] args) 
    {
        Pokemon p1;
        p1 = new Pokemon("Charizard", Type.FIRE);
    }

}