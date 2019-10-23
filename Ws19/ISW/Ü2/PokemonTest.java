public class PokemonTest
{
    public static void main(String[] args) 
    {
        Pokemon arbok = new Pokemon("Arbok", Type.POISON);
        Pokemon victini = new Pokemon("Victini", Type.FIRE);
        
        // Testen des Constructors und der toString() Funktion
        System.out.println("\nTesting Constructor and toString() of the created Pokemon:");
        System.out.println("----------------------------------------------------------");
        System.out.println(arbok);
        System.out.println();
        System.out.println(victini);
        System.out.println("----------------------------------------------------------\n");

        // Testen des Getters von name
        System.out.println("Testing getName() of Pokemon 'Arbok':");
        System.out.println("----------------------------------------------------------");
        System.out.println(arbok.getName());
        System.out.println("----------------------------------------------------------\n");

        // Testen des Getters von Type
        System.out.println("Testing getType() of Pokemon 'Arbok':");
        System.out.println("----------------------------------------------------------");
        System.out.println(arbok.getType());
        System.out.println("----------------------------------------------------------\n");

        // Testen des Setters von Name
        System.out.println("Testing setName('Missingno') of Pokemon 'Arbok':");
        System.out.println("----------------------------------------------------------");
        arbok.setName("Missigno");
        System.out.println(arbok.getName());
        System.out.println("----------------------------------------------------------\n");
        
        // Testen des Setters von Type
        System.out.println("Testing setType(Type.FIRE) of Pokemon 'Arbok':");
        System.out.println("----------------------------------------------------------");
        arbok.setType(Type.FIRE);
        System.out.println(arbok.getType());
        System.out.println("----------------------------------------------------------\n");

        // Felix
        Trainer ash = new Trainer("Ash","Ketchup");
        Trainer gary = new Trainer("Gary","Birch");

        // Set Pokemon to default
        arbok.setType(Type.POISON);
        arbok.setName("Arbok");

        // create new Pokemon;
        Pokemon shiggy = new Pokemon("Shiggy", Type.WATER);
        Pokemon gengar = new Pokemon("Gengar", Type.POISON);
        Pokemon karpador = new Pokemon("Karpador", Type.WATER);
        Pokemon incineroar = new Pokemon("Incineroar", Type.FIRE);



        // Adding Pokemon
        System.out.println("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
        System.out.println("Beginning to test Trainer Objekts:");
        System.out.println("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");

        System.out.println("\nash.getPokemons() before adding any Pokemon:" +
                           "\n(expected: [])\n");
        System.out.println(ash.getPokemons());
        System.out.println("----------------------------------------------------------");

        System.out.println("\nash.getPokemns() after ash.addPokemon(victini):" +
                           "\n(expected: toString() of victini)\n");
        ash.addPokemon(victini);
        System.out.println(ash.getPokemons());
        System.out.println("----------------------------------------------------------");

        System.out.println("\nash.getPokemns() after ash.addPokemon(shiggy):" +
                           "\n(expected: toString() of victini and shiggy)\n");
        ash.addPokemon(shiggy);
        System.out.println(ash.getPokemons());
        System.out.println("----------------------------------------------------------");

        System.out.println("\nash.getPokemns() after ash.addPokemon(karpador):" +
                           "\n(expected: toString() of victini, shiggy and karpador)\n");
        ash.addPokemon(karpador);
        System.out.println(ash.getPokemons());
        System.out.println("----------------------------------------------------------\n");

        // Felix

        System.out.println("\nash.pokemonAt(1),getting ash's second pokemon" +
                "\n(expected: toString of shiggy)\n");
        System.out.println(ash.pokemonAt(1));
        System.out.println("----------------------------------------------------------");


    }
}