# City Lead for Zeal 8-bit OS

Choose between being mayor of the city or the don of the mafia.  Control the city and complete your goals.

A keyboard based game for Zeal 8-bit http://zeal8bit.com/

## Game Setup

    The 7×7 grid represents the city, with each tile representing a district.
    The Mayor and Mafia Don each start with one controlled district (placed diagonally opposite).
    Districts can be Neutral, Mayor-Controlled, or Mafia-Controlled.
    Each district has a population, income, and influence rating.

## Turn Structure

Each turn, players take actions and then resolve events. A turn consists of:

- Income Collection – Players collect income from controlled districts.
- Action Phase – Players take up to 3 actions (see below).
- Event Resolution – Random city events may affect districts.
- Control Check – If one player controls at least 70% of the city, they win.

## Actions (Choose up to 3 per turn)
### For the Mayor:

- Build Infrastructure – Improve a district (e.g., police station, school, park) to increase loyalty. money -50, influence +1 for district
- Pass a Law – Implement policies that affect multiple districts. money -100, influence +1 for 3 districts
- Deploy Police – Attempt to reclaim Mafia-controlled districts. influrnce +1
- Campaign – Spend resources to increase influence in a neutral district. money -250, influence +3 for 2 districts
- Investigate Corruption – Lower the Mafia’s influence in a district. influence +2 for negative district

### For the Mafia Don:

- Bribe Officials – Gain control of a neutral or Mayor-influenced district. money -250, influence -2 for 1 district
- Extort Businesses – Gain extra income from controlled districts. money +100, influence -1 for 3 districts
- Intimidate – Lower the Mayor’s influence in a contested district. influence -1
- Smuggle Goods – Gain resources at the risk of exposure. money +250 5/6 times, but 3 controlled districts to 0 in 1/6 times
- Assassinate – Temporarily remove a Mayor’s official from play. money -1000, influence -3 for 1 positive district

## Conflict Resolution

- If both sides have influence in a contested district, a power struggle occurs.
- Power struggles are resolved based on:
       - Influence Levels (higher wins)
       - Modifiers (e.g., police presence, bribes, infrastructure)
       - Chance Factor (small random adjustment)

## Win Conditions

- Mayor Victory: Control 70% or more of the city OR expose the Mafia Don’s operations completely.
- Mafia Victory: Control 70% or more of the city OR force the Mayor to resign by causing unrest.