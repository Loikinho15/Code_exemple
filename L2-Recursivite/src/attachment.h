#ifndef ATTACHMENT_H
#define ATTACHMENT_H
#include "cstddef"

struct Game_state;
//Bien que le code soit en snake_case nous avons laissé le code déjà présent en CamelCase
//afin de ne pas modifier le code qui ne vient pas de nous.
enum AttachementType {
    FILLE_HAUT,
    FILLE_BAS,
    DAME_HAUT,
    DAME_BAS,
    ARROSOIR_GAUCHE,
    ARROSOIR_DROIT,
    GATEAU_GAUCHE,
    GATEAU_DROIT,
    ARROSOIR_INVERSE,
    NONE };

enum class AttachementDirection {
    HAUT,
    DROITE,
    BAS,
    GAUCHE
  };


AttachementType get_linked_attachement(const AttachementType &attachement);

bool are_attachements_matching(const Game_state &game_state, const AttachementDirection &attachement_direciton, size_t placed_piece_index, size_t piece_index);

#endif //ATTACHMENT_H
