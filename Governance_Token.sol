// SPDX-License-Identifier: MIT
// OpenZeppelin Contracts (last updated v4.5.0) (token/ERC20/extensions/ERC20Votes.sol)

pragma solidity ^0.8.0;
import "@openzeppelin/contracts/token/ERC20/ERC20.sol";

contract Governance_Token is ERC20  {
    address public admin;
    constructor()ERC20("VoteGOVERN","VG"){
        _mint(msg.sender,1000 *10**18);
        admin = msg.sender;
    }
    function mint(address to,uint256 amount) external {
        require(admin == msg.sender,"admin only calling");
        _mint(to,amount);
    }
    function burn(uint256 amount) external {
        _burn(msg.sender,amount);
    }

}
