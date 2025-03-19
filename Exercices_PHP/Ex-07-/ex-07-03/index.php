<?php
    require_once('Rectangle.php');
    session_start();
    require_once('header.html');

	
		
    // le formulaire est affiché en tous les cas:
    require_once('form.html');
    
    if ( isset($_POST['valid_rect_form'])) {
        // on vient de recevoir un formulaire pour créer un nouveau rectangle:
        
        // vérification des champs:
        if ($_POST['width'] == "" || $_POST['height'] == "" || $_POST['color'] == '') {
            echo '<font color="red">Merci de remplir tous les champs.</font><br>';
        } else {
            // création du rectangle avec les paramètres reçus:
            $myNewRect = new ColoredRectangle($_POST['width'], $_POST['height'], $_POST['color']);
            
            // ajout du rectangle dans la liste:
            $_SESSION['rectArray'][] = $myNewRect;
        }
        
    }
    
    // gestion du logout:
    if ( isset($_POST['valid_logout_form'])) {
        session_destroy();
        $_SESSION = array();
    }
        
    // affichage des rectangles existants:
    if (isset($_SESSION['rectArray'])) {
        echo "Liste des rectangles:<br>";
        echo '<table border="1">';
        echo '<tr> <th>largeur</th> <th>hauteur</th> <th>surface</th> <th>couleur</th> </tr>';
        foreach ($_SESSION['rectArray'] as $myRect) {
            $width = $myRect->getWidth();
            $height = $myRect->getHeight();
            $surface = $myRect->getSurface();
            $color = $myRect->GetColor();
            echo "<tr> <td>$width</td> <td>$height</td> <td>$surface</td> <td>$color</td> </tr>";
        }
        echo '</table>';
        require_once('reset_form.html');
   }
   
   require_once('footer.html');
?>
