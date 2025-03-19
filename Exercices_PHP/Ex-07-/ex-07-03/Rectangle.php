<?php

class Rectangle {
    protected $width = null;
    protected $height = null;

    function __construct($width=0, $height=0) {
        $this->setWidth($width);
        $this->setHeight($height);
        
    }

    function getWidth() { return $this->width; }
    function getHeight() { return $this->height; }
    function setWidth($width) {
        $this->width = $width;  
    }
    function setHeight($height) {
        $this->height = $height;  
    }

    function getSurface() {
        return $this->width * $this->height;
    }
    
}

class ColoredRectangle extends Rectangle{
    
    public $color = null;

    function __construct($width=0, $height=0, $color){

        parent::__construct($width,$height);
        $this->SetColor($color);
    }

    function SetColor($color){
        $this->color = $color;
    }

    function GetColor(){
        return $this->color;
    }
}

?>
