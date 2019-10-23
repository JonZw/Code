public class Trainer // Felix
{
    private String firstName;
    private String lastName;

    // Jonathan
    private java.util.ArrayList<Pokemon> pokemons;

    // Felix
    public Trainer(String _fname, String _lname)
    {
        firstName = _fname;
        lastName = _lname;
        pokemons = new java.util.ArrayList<Pokemon>();
    }

    public String getFname()
    {
        return firstName;
    }

    public String getLname()
    {
        return lastName;
    }

    // Begin Jonathan
    public void addPokemon(Pokemon newPokemon)
    {
        if(newPokemon.getTrainer() == null)
        {
            pokemons.add(newPokemon);
            newPokemon.setTrainer(this);
        }
    }

    public Pokemon pokemonAt(int index)
    {
        if (index < pokemons.size())
        {
            return pokemons.get(index);
        }
        return null;
    }

    public java.util.ArrayList<Pokemon> getPokemons()
    {
        return pokemons;
    }

    public java.util.ArrayList<Pokemon> getPokemons(Type type)
    {
        java.util.ArrayList<Pokemon> pokemonsOfType = new java.util.ArrayList<Pokemon>();
        for (Pokemon pokemon : pokemons)
        {
            if (pokemon.getType() == type)
            {
                pokemonsOfType.add(pokemon);
            }
        }
        return pokemonsOfType;
    }
    //End Jonathan

    @Override
    public String toString()
    {
        return "Name: " + lastName
                + "\nVorname: " + firstName;
    }
}
