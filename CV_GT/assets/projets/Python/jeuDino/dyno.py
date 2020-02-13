import pygame
import time
from pygame.locals import *

pygame.display.init()

fenetre = pygame.display.set_mode((640,480), RESIZABLE)

fond = pygame.image.load("17429297_xl.jpg").convert()
position_fond = fond.get_rect()
fenetre.blit(fond, position_fond)

class Dino():
	BLOC = 624
	WALKING = 380
	JUMPING = 150
	vitesse = 10
	GRAVITE = 1
	degats = 100

	def __init__(self):
		self.perso = pygame.image.load("dinosaur-05.png").convert_alpha()
		self.position_perso = self.perso.get_rect()
		self.position_perso.x = 0
		self.position_perso.y = self.WALKING
	
	def posDepart(self):
		if self.position_perso.x < 0:
			self.position_perso.x = 0

	def pasPlusLoin(self):
		if self.position_perso.x >= 540:
			self.position_perso.x = 540

	def pasPlusHaut(self):
		if self.position_perso.y <= 0:
			self.position_perso.y = 0

	def sauter(self):
		self.position_perso = self.position_perso.move(0,-10*self.vitesse)


	def limit(self):
		depart = self.posDepart()
		stop = self.pasPlusLoin()
		top = self.pasPlusHaut()

	def gravity(self):
		if self.position_perso.y < self.WALKING:
			self.position_perso = self.position_perso.move(0,self.GRAVITE)

	def degat(self):
		self.position_perso = self.position_perso.move(-10,0)
		self.degats -= 1
		if self.degats == 0:
			self.perso = pygame.transform.flip(self.perso, 0, 100)

class Tekki():
	def __init__(self,x,y,imagepath):
		self.ennemi = pygame.image.load(imagepath).convert_alpha()
		self.position_ennemi = self.ennemi.get_rect()
		self.position_ennemi.x = x
		self.position_ennemi.y = y
		self.start_y = y
		self.start_x = x
		self.imagepath = imagepath

	def mouv(self):
		self.position_ennemi.x -= 1
		if self.position_ennemi.x < 0:
			self.position_ennemi.x = self.start_x
			self.resurrect()
		if BossDragon.position_dragon.x <= 450:
			self.position_ennemi.y = -100

	def death(self):
		self.position_ennemi.y += self.position_ennemi.height*0.9
		self.ennemi = pygame.transform.scale(self.ennemi, (100, 10))

	def resurrect(self):
		self.position_ennemi.y = self.start_y
		self.ennemi = pygame.image.load(self.imagepath).convert_alpha()

	def otherDeath(self):
		self.ennemi = pygame.transform.flip(self.ennemi, 0, -100)
		self.position_ennemi.y += 1000

class Boss():
	puissance = 5
	def __init__(self,x,y):
		self.dragon = pygame.image.load("dragon.png").convert_alpha()
		self.position_dragon = self.dragon.get_rect()
		self.position_dragon.x = x
		self.position_dragon.y = y
		self.start_x = x
		self.start_y = y

	def mouvBoss(self):
		if self.position_dragon.x != 250:
			self.position_dragon.x -= 1

	def deathBoss(self):
		self.position_dragon.y += 5
		self.puissance -= 1
		if self.puissance == 0:
			self.position_dragon = self.position_dragon.move(0,1000)
			return True
		return False

pygame.display.flip()

continuer = 1
stop = 0
etat = 1
WALKING = 380
pygame.key.set_repeat(100, 30)
clock = pygame.time.Clock()
myDino = Dino()
FirstTekki = Tekki(560,WALKING,"perso.png")
SecondTekki = Tekki(1060,160,"billBall.png")
BossDragon = Boss(2000,50)

while continuer:
	for event in pygame.event.get():
		if event.type == KEYDOWN:
			if event.key == K_RIGHT:
				myDino.position_perso = myDino.position_perso.move(myDino.vitesse,0)
				myDino.limit()
			if event.key == K_LEFT:
				myDino.position_perso = myDino.position_perso.move(-myDino.vitesse,0)
				myDino.limit()
			if event.key == K_UP:
				myDino.sauter()
				myDino.limit()
		if event.type == QUIT:
			continuer = 0

	myDino.gravity()
	FirstTekki.mouv()
	SecondTekki.mouv()
	BossDragon.mouvBoss()
	fenetre.blit(fond, position_fond)
	fenetre.blit(myDino.perso, myDino.position_perso)
	fenetre.blit(FirstTekki.ennemi, FirstTekki.position_ennemi)
	fenetre.blit(SecondTekki.ennemi, SecondTekki.position_ennemi)
	fenetre.blit(BossDragon.dragon, BossDragon.position_dragon)

	if myDino.position_perso.colliderect(FirstTekki.position_ennemi) and myDino.position_perso.y == FirstTekki.position_ennemi.y:
		myDino.degat()

	if myDino.position_perso.colliderect(SecondTekki.position_ennemi) and myDino.position_perso.y == SecondTekki.position_ennemi.y:
		myDino.degat()

	if FirstTekki.position_ennemi.colliderect(myDino.position_perso) and myDino.position_perso.x == FirstTekki.position_ennemi.x:
		FirstTekki.death()

	if SecondTekki.position_ennemi.colliderect(myDino.position_perso) and myDino.position_perso.x == SecondTekki.position_ennemi.x:
		SecondTekki.otherDeath()

	if myDino.degats <= 100 and myDino.degats > 90:
		barre10 = pygame.image.load("barre_10.png").convert_alpha()
		positionbarre = barre10.get_rect()
		fenetre.blit(barre10,positionbarre)
	elif myDino.degats <= 90 and myDino.degats > 80:
		barre9 = pygame.image.load("barre_9.png").convert_alpha()
		positionbarre = barre9.get_rect()
		fenetre.blit(barre9,positionbarre)
	elif myDino.degats <= 80 and myDino.degats > 70:
		barre8 = pygame.image.load("barre_8.png").convert_alpha()
		positionbarre = barre8.get_rect()
		fenetre.blit(barre8,positionbarre)
	elif myDino.degats <= 70 and myDino.degats > 60:
		barre7 = pygame.image.load("barre_7.png").convert_alpha()
		positionbarre = barre7.get_rect()
		fenetre.blit(barre7,positionbarre)
	elif myDino.degats <= 60 and myDino.degats > 50:
		barre6 = pygame.image.load("barre_6.png").convert_alpha()
		positionbarre = barre6.get_rect()
		fenetre.blit(barre6,positionbarre)
	elif myDino.degats <= 50 and myDino.degats > 40:
		barre5 = pygame.image.load("barre_5.png").convert_alpha()
		positionbarre = barre5.get_rect()
		fenetre.blit(barre5,positionbarre)
	elif myDino.degats <= 40 and myDino.degats > 30:
		barre4 = pygame.image.load("barre_4.png").convert_alpha()
		positionbarre = barre4.get_rect()
		fenetre.blit(barre4,positionbarre)
	elif myDino.degats <= 30 and myDino.degats > 20:
		barre3 = pygame.image.load("barre_3.png").convert_alpha()
		positionbarre = barre3.get_rect()
		fenetre.blit(barre3,positionbarre)
	elif myDino.degats <= 20 and myDino.degats > 10:
		barre2 = pygame.image.load("barre_2.png").convert_alpha()
		positionbarre = barre2.get_rect()
		fenetre.blit(barre2,positionbarre)
	elif myDino.degats <= 10 and myDino.degats > 0:
		barre1 = pygame.image.load("barre_1.png").convert_alpha()
		positionbarre = barre1.get_rect()
		fenetre.blit(barre1,positionbarre)
	elif myDino.degats == 0:
		continuer = 0

	if BossDragon.position_dragon.colliderect(myDino.position_perso) and myDino.position_perso.x == BossDragon.position_dragon.x:
		if BossDragon.deathBoss() == True:
			stop = 1

	if stop == 1:
		felicitation = pygame.image.load("win.jpg").convert()
		position_win = felicitation.get_rect()
		fenetre.blit(felicitation,position_win)

	pygame.display.flip()

	clock.tick(100)