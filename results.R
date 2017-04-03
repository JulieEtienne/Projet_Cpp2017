data <- read.csv("resultats.csv",header = TRUE)
data[1,1]
A_init <- seq(0,50,10)
t <- seq(1,1500,100)
Lt <- c()
St <- c()
La <- c()
Sa <- c()


for ( i in 1:90)
{
  for (a in A_init)
  {
    if (data[i,3] == a)
    {
      Lt <- c(Lt, a)
    }
    print(Lt)
  }
}

