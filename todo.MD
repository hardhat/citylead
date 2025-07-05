# City Lead MVP Development TODO

## Core Game Loop Implementation

### Turn Management
- [ ] Add turn counter increment system in `update_game()`
- [ ] Implement player switching logic (mayor → mafia → mayor)
- [ ] Add actions remaining counter per turn (max 3 actions per player)
- [ ] Create turn end conditions (all actions used or player manually ends turn)
- [ ] Add visual indicator for current player's turn

### Game State Management
- [ ] Add game mode states (SELECTING_DISTRICT, SELECTING_ACTION, CONFIRMING_ACTION)
- [ ] Implement action selection menu when player presses action button on district
- [ ] Add confirmation dialogs for actions that cost money
- [ ] Create cancel/back functionality for action selection

## District System

### Random District Generation
- [ ] Implement random wealth assignment for neutral districts at game start
- [ ] Add random population generation (50-200 based on wealth)
- [ ] Create function to generate neutral districts with varying influence (0-2)

### District Control Logic
- [ ] Implement influence threshold system for district control
- [ ] Add district state change logic when influence crosses thresholds
- [ ] Create territory counting function to update `players[].teritories`
- [ ] Add visual feedback when districts change control

## Player Actions - Mayor

### Build Infrastructure
- [ ] Add "Build Infrastructure" action (cost: $500, effect: +1 influence to selected district)
- [ ] Implement money deduction and influence modification
- [ ] Add visual confirmation and error handling for insufficient funds
- [ ] Create infrastructure visual indicator on district tiles

### Pass a Law
- [ ] Implement "Pass a Law" action (cost: $1000, effect: +1 influence to 3 adjacent districts)
- [ ] Add adjacent district calculation logic
- [ ] Handle edge cases for districts near grid boundaries
- [ ] Add visual highlighting of affected districts

### Deploy Police
- [ ] Create "Deploy Police" action (+1 influence to selected district, no cost)
- [ ] Add special effect against mafia districts (extra +1 influence)
- [ ] Implement police presence visual indicator

### Campaign
- [ ] Add "Campaign" action (cost: $2500, effect: +3 influence to 2 selected districts)
- [ ] Implement multi-district selection for this action
- [ ] Add district selection UI for choosing 2 targets

### Investigate Corruption
- [ ] Create "Investigate Corruption" action (effect: +2 influence vs mafia district)
- [ ] Add restriction to only work on mafia-controlled districts
- [ ] Implement negative influence reduction logic

## Player Actions - Mafia

### Bribe Officials
- [ ] Implement "Bribe Officials" action (cost: $2500, effect: -2 influence to target)
- [ ] Add restriction to neutral or mayor districts only
- [ ] Create bribery visual effect

### Extort Businesses
- [ ] Add "Extort Businesses" action (+$1000, -1 influence to 3 controlled districts)
- [ ] Implement selection of controlled districts for extortion
- [ ] Add risk/reward calculation display

### Intimidate
- [ ] Create "Intimidate" action (-1 influence to mayor district, no cost)
- [ ] Add restriction to mayor-controlled districts
- [ ] Implement intimidation visual feedback

### Smuggle Goods
- [ ] Add "Smuggle Goods" action with random outcome
- [ ] Implement 5/6 chance of +$2500, 1/6 chance of losing 3 districts
- [ ] Create risk warning dialog before action
- [ ] Add random number generation for outcome

### Assassinate
- [ ] Implement "Assassinate" action (cost: $10000, -3 influence to mayor district)
- [ ] Add high-cost confirmation dialog
- [ ] Create dramatic visual effect for assassination

## Income System

### Turn-Based Income
- [ ] Implement income collection at start of each turn
- [ ] Calculate income based on controlled districts and their wealth
- [ ] Add income rates: Poor ($100), Middle ($200), Rich ($500)
- [ ] Display income gained notification

### Income Display
- [ ] Add income preview for next turn
- [ ] Show potential income for contested districts
- [ ] Create income breakdown by district type

## Action Menu System

### Menu UI
- [ ] Create action selection menu overlay
- [ ] Add keyboard navigation for action selection (UP/DOWN arrows)
- [ ] Implement action descriptions and costs display
- [ ] Add "Cancel" option to return to district selection

### Action Validation
- [ ] Check if player has sufficient money before allowing action
- [ ] Validate action targets (e.g., can only bribe non-mafia districts)
- [ ] Add error messages for invalid actions
- [ ] Implement action availability based on game state

## Win Condition System

### Territory Control Victory
- [ ] Add function to calculate percentage of controlled districts
- [ ] Check for 70% control victory condition after each turn
- [ ] Implement victory screen with winner announcement

### Special Victory Conditions
- [ ] Add "expose mafia" victory condition for mayor (investigate all mafia districts)
- [ ] Implement "mayor resignation" condition for mafia (control city hall district)
- [ ] Create special victory detection logic

## Random Events System

### Event Framework
- [ ] Create random event structure and data
- [ ] Implement event triggering system (end of each turn)
- [ ] Add event description display
- [ ] Create event resolution effects

### Event Types
- [ ] Economic boom/bust events (+/-$ to all players)
- [ ] Population migration (change district populations)
- [ ] Scandal events (influence changes)
- [ ] Infrastructure events (affect specific districts)

## User Interface Improvements

### Visual Feedback
- [ ] Add animation for district control changes
- [ ] Implement money change indicators (+/- floating text)
- [ ] Create influence change visual effects
- [ ] Add sound effects for actions (if audio system allows)

### Information Display
- [ ] Improve action menu with better formatting
- [ ] Add help screen explaining all actions
- [ ] Create detailed district information panel
- [ ] Add game statistics tracking

## Input and Controls

### Enhanced Controls
- [ ] Add action button (A/Enter) for selecting districts and actions
- [ ] Implement context-sensitive button prompts
- [ ] Add quick-access keys for common actions
- [ ] Create control help overlay

### Input Validation
- [ ] Add input debouncing to prevent accidental multiple actions
- [ ] Implement proper state management for different input modes
- [ ] Add confirmation for destructive actions

## Game Balance and Polish

### Balance Testing
- [ ] Test and adjust action costs for balanced gameplay
- [ ] Verify win conditions are achievable for both sides
- [ ] Balance starting resources and district values
- [ ] Adjust influence thresholds for district control

### Bug Fixes and Optimization
- [ ] Fix any display issues with district rendering
- [ ] Optimize text rendering for better performance
- [ ] Add bounds checking for all array accesses
- [ ] Implement proper memory management

### Save/Load System (Optional)
- [ ] Add basic game state serialization
- [ ] Implement save game functionality
- [ ] Create load game menu option
- [ ] Add autosave between turns

## Final MVP Requirements

### Core Gameplay Loop
- [ ] Complete turn-based gameplay with all actions functional
- [ ] Working win/lose conditions
- [ ] Proper player switching and turn management
- [ ] All mayor and mafia actions implemented

### Minimum Viable Features
- [ ] District control and influence system working
- [ ] Money and resource management
- [ ] Basic random events
- [ ] Clear victory conditions
- [ ] Intuitive controls and UI

### Testing and Polish
- [ ] Playtest complete games from start to finish
- [ ] Verify all game mechanics work as designed
- [ ] Test edge cases and error conditions
- [ ] Final balance adjustments based on playtesting