package atividades.lista6.questao10;

public class Magazine extends LibraryItem {
    private int issueNumber;

    public Magazine(String title, int issueNumber) {
        super(title);
        this.issueNumber = issueNumber;
    }

    public int getIssueNumber() {
        return issueNumber;
    }

    @Override
    public String getItemType() {
        return "Revista";
    }

    @Override
    public String toString() {
        return super.toString() + " - Edição: " + issueNumber;
    }
}