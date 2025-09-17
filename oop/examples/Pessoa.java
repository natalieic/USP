import java.time.LocalDate;
import java.time.Period;

public class Pessoa {
    private String name;
    private LocalDate birthDate;
    private float weight, height;

    // Constructor method
    public Pessoa(String name, LocalDate birth, float weight, float height){
        this.name = name;
        this.birthDate = birth;
        this.weight = weight;
        this.height = height;
    }

    public Pessoa(){
        this("", 0, 0.0, 0.0);
    }

    // Getter methods
    public String getName(){
        return name;
    }
    public float getWeight(){
        return weight;
    }
    public float getHeight(){
        return height;
    }
    public LocalDate getBirthDate(){
        return birthDate;
    }

    // Setter methods
    public void setName(String newName){
        name = newName;
    }
    public void setBirth(LocalDate date){
        birthDate = date;
    }
    public void setWeight(float newWeight){
        weight = newWeight;
    }
    public void setHeight(float newHeight){
        height = newHeight;
    }

    public int idade(){
        return Period.between(this.birthDate, LocalDate.now()).getYears();
    }
}