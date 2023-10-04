def get_smallest_card(cards, suit, trump):
    suit_cards = [card for card in cards if card[0] == suit]
    if suit_cards:
        return min(suit_cards)
    elif trump in cards:
        return min([card for card in cards if card[0] == trump])
    else:
        non_trump_suits = ['c', 'd', 'h', 's']
        other_suits = [card for card in cards if card[0] in non_trump_suits and card[0] != suit and card[0] != trump]
        return min(other_suits)

def get_optimal_card(players, self_name, played_cards, self_cards, trump):
    player_order = players.split(',')
    team1 = [player_order[0], player_order[2]]
    team2 = [player_order[1], player_order[3]]
    
    largest_card = max(played_cards, key=lambda x: x[1:])
    
    if largest_card[0] in [self_name, team2[0], team2[1]]:
        return min(self_cards)
    
    suit_of_round = played_cards[0][0]
    self_suit_cards = [card for card in self_cards if card[0] == suit_of_round]
    
    if trump not in [card[0] for card in played_cards]:
        if self_suit_cards:
            larger_suit_cards = [card for card in self_suit_cards if card[1:] > largest_card[1:]]
            if larger_suit_cards:
                return min(larger_suit_cards)
            else:
                return min(self_suit_cards)
        elif trump in [card[0] for card in self_cards]:
            return get_smallest_card(self_cards, trump, trump)
        else:
            return min(self_cards)
    else:
        trump_cards = [card for card in self_cards if card[0] == trump]
        higher_trump_cards = [card for card in trump_cards if card[1:] > largest_card[1:]]
        if higher_trump_cards:
            return min(higher_trump_cards)
        else:
            return get_smallest_card(trump_cards, trump, trump)

# Sample Input
input_str = "players:tom,dick,harry,john;self:john;trumph:s;dick:s10;tom:s2;harry:ca;cards:s3,sk,ha"

# Parse input
input_components = input_str.split(';')
players = input_components[0].split(':')[1]
self_name = input_components[1].split(':')[1]
played_cards = [component.split(':') for component in input_components[2:5]]
self_cards = input_components[5].split(':')[1].split(',')
trump = input_components[6].split(':')[1]

# Convert played cards to a list of tuples
played_cards = [(card[0], card[1:]) for card in played_cards]

# Get optimal card
optimal_card = get_optimal_card(players, self_name, played_cards, self_cards, trump)
print(optimal_card)
