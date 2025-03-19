#include "attachment.h"
#include "game.h"
#include "pieces.h"

AttachementType get_linked_attachement(const AttachementType &attachement) {
    const int attachement_value = attachement;
    return static_cast<AttachementType>(attachement_value + (attachement_value % 2 == 0 ? 1 : -1));
}

bool are_attachements_matching(const Game_state &game_state, const AttachementDirection &attachement_direciton, size_t placed_piece_index, const size_t piece_index) {
    const Pieces_state &pieces_state = game_state.pieces_state;
    const Index_in_game_to_pieces_index &index_in_game_to_pieces_index = game_state.index_in_game_to_pieces_index;
    const auto candidate_piece = pieces_state[piece_index];
    auto attachment_direction_value = static_cast<size_t>(attachement_direciton);

    const size_t *current_checking_index_ptr = index_in_game_to_pieces_index[placed_piece_index];

    // no piece at this position
    if (current_checking_index_ptr == nullptr) {
        return true;
    }
    size_t current_checking_index = *current_checking_index_ptr;
    // if the piece is not placed, we don't care about her.
    if (!pieces_state[current_checking_index].is_placed) {
        return true;
    }

    const Piece_state &checking_piece = pieces_state[current_checking_index];
    return get_linked_attachement(
               candidate_piece.content[(attachment_direction_value - candidate_piece.rotation_count) % 4]) ==
           checking_piece.content[(attachment_direction_value - checking_piece.rotation_count + 2) % 4];
}