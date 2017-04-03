#!/usr/bin/env Rscript

nom <- "resultats_mut_D"

png(file= paste(nom,"+.png",sep=""))

data <- read.csv(paste(nom,".csv",sep=""),header = FALSE)
data <- as.matrix(data)
data


A_init <- seq(0,50,10)
t <- seq(1,1500,100)


persp(A_init,t,data,theta=230,phi=15,xlab='[A]i',ylab='T',zlab='Nombre de bactéries',col="chartreuse1",expand=0.5,shade=0.8,ticktype="detailed")

dev.off()

png(file = paste(nom,"-.png",sep=""))
persp(A_init,t,data,theta=-230,phi=15,xlab='[A]i',ylab='T',zlab='Nombre de bactéries',col="chartreuse1",expand=0.5,shade=0.8,ticktype="detailed")
dev.off()
