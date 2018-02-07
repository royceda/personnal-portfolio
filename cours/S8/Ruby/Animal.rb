#!/usr/bin/ruby

require 'sqlite3'


class EtreVivant
  def coeur_bat
    puts "Boum Boum"
  end
end

#heritage

class Animal < EtreVivant 
@@total_cree = 0 #variable de class
@@db

  def initialize
    
    begin 
      @@db = SQLite3::Database.new":memory:"
    rescue SQLite3::Exception => e
      puts "Exception"
      puts e
    ensure
      db.close if db
    end
    @name         = "animal"
    @parole       = "aaaa"
    @age          = 1
    @@total_cree += 1
  end
  
  def initialize(name = '', parle = '', age = 3)
    @name   = name
    @parole = parle
    @age    = age
    @@total_cree += 1
  end

  def self.total
    return @@total_cree;
  end

  def set_parle(parle)
    @parle = parle
  end

  def set_age(age)
    @age = age
  end

  def set_name(name)
    @name = name
  end
  
  def get_name
    return @name
  end

  def get_parle
    return @parle
  end

  def get_age
    return @age
  end

  def save
    begin
      db = SQLite3::Database.open "Animal.db"
      db.execute "CREATE TABLE IF NOT EXISTS animal(Id integer AUTO_INCREMENT primary key, name text, parle text, age integer)"
      db.execute "insert into animal( name, parle, age)  values( ' #{@name}', ' #{@parle}', #{@age})"
      puts "insert #{@name} :OK"

    rescue SQLite3::Exception => e
      puts "Exception occured"
      puts e
    ensure
      db.close if db
    end
  end
end


dog = Animal.new
cat = Animal.new("cat", "miaouuu", 2)


puts " #{dog.get_name} makes #{dog.get_parle} and is #{dog.get_age} old"
puts " #{cat.get_name} makes #{cat.get_parle} and is #{cat.get_age} old"

dog.coeur_bat
dog.set_name("dog")
dog.set_age(14)
dog.set_parle("wouafff ")

puts "dog makes #{dog.get_parle} and is #{dog.get_age} old"
puts "creation:  #{Animal.total}"

dog.save
cat.save
