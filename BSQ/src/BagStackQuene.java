import java.util.*;

class Bag<item> implements Iterable<item> {
private node first;
private class node
{
    node(item it){date=it;};
    node next;
    item date;
}
public void add(item it)//前加
{
    node oldfirst = first;
    first = new node(it);
    first.next = oldfirst;
}
public Iterator<item> iterator() {
        return new bagIterator();
    }
private class bagIterator implements Iterator<item>
{

    private node current=first;
    @Override
    public boolean hasNext() {
        return current!=null;
    }
    @Override
    public item next() {
        item date=current.date;
        current=current.next;
        return date;
    }
    public void remove(){}

}
}

class stack<item> implements Iterable<item>
{
private node first;

    @Override
    public Iterator<item> iterator() {
        return new stackiterator();
    }
    private class stackiterator implements Iterator<item>{
node current=first;
        @Override
        public boolean hasNext() {
            return current!=null;
        }

        @Override
        public item next() {
            item date=current.date;
            current=current.next;
            return date;
        }
    }

    private class node {
    item date;
    node next;
}
public void push(item date){
    node old =first;
    first=new node();
    first.date=date;
    first.next=old;
}
public item pop(){
    node old=first;
    first=old.next;
    return old.date;
}

}

class quene<item> //要考虑是否first和last 指向同一个节点；
{
    private node first;
    private node last;
    private class node{
        node next;
        item date;
    }
    public void push(item date){
      node current=new node();
        current.date=date;
        last.next=current;
        last=current;
        if(first==null)
            first=last;
    }
    public item pop(){
        item date= first.date;
        first=first.next;
        if(first==null) last=null;
        return date;
    }
}

class text
{
    public static void  main (String args[]){
       Bag bag=new Bag<Integer>();
       for(int i=0;i<5;i++)
         {
           bag.add(i);
         }
       Iterator<Bag> iterator= bag.iterator();
       while(iterator.hasNext())
       {
           System.out.println(iterator.next());
       }
    }
}



