library(foreign)
credito = read.arff("C:\\Users\\lab56\\Downloads\\credit.g.arff")
install.packages("e1071", dependencies=TRUE)
library(e1071)
amostra = sample(2, 1000, replace = T, prob = c(0.7,0.3))
creditoTreino = credito[amostra==1]
creditoTeste = credito[amostra==2]
dim(creditoTreino)
dim(creditoTeste)
modelo <- naiveBayes(class ~., creditoTreino)
modelo
predicao <- predict(modelo, creditoTeste)
head(predicao)
confusao = table(creditoTeste$class, predicao)
confusao

taxaAcerto = (confusao[1] + confusao[4]) / sum(confusao)
taxaErro = (confusao[2] + confusao[3]) / sum(confusao)
taxaAcerto
taxaErro