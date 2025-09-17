import math

class numPuz :

    def __init__ (self, tiles) :
        self.config = tiles
        self.order = int(math.sqrt(len(tiles)))
        self.zeroLoc = tiles.index(0)

    def slideRight (self) :
        if self.zeroLoc % self.order != 0 :     # removed + self.order
            # self.zeroLoc = self.config[self.zeroLoc - 1]
            # self.config[self.zeroLoc + 1] = 0
            self.config[self.zeroLoc], self.config[self.zeroLoc - 1] = self.config[self.zeroLoc - 1], 0
            self.zeroLoc -= 1
            return True
        return False

    def slideLeft (self) :
        if (self.zeroLoc + 1) % self.order != 0 :
            self.config[self.zeroLoc], self.config[self.zeroLoc + 1] = self.config[self.zeroLoc + 1], 0
            self.zeroLoc += 1
            return True
        return False

    def slideDown (self) :
        if self.zeroLoc >= self.order :
            self.config[self.zeroLoc - self.order], self.config[self.zeroLoc] = 0, self.config[self.zeroLoc - self.order]
            self.zeroLoc -= self.order
            return True
        return False
        
    def slideUp (self) :
        if self.zeroLoc < (self.order**2 - self.order) :
            self.config[self.zeroLoc], self.config[self.zeroLoc + self.order] = self.config[self.zeroLoc + self.order], 0
            self.zeroLoc += self.order
            return True
        return False
    
    def isSolved (self) :
        return all(location == tile for location, tile in enumerate(self.config))
    
    def display (self) :

    def printDiv (self) :
        

    def printRow (self) :


    
